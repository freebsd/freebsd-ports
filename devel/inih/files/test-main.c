#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ini.h"

// Define a structure to hold application configuration data
typedef struct {
    int version;
    bool enable_ipv6;
    const char* name;
    const char* email;
} configuration;

// Callback handler called by inih for each key-value pair found
static int handler(void* user, const char* section, const char* name, const char* value) {
    configuration* pconfig = (configuration*)user;

    // Helper macro to accurately match section and key names
    #define MATCH(s, n) (strcmp(section, s) == 0 && strcmp(name, n) == 0)

    if (MATCH("protocol", "version")) {
        pconfig->version = atoi(value);
    } else if (MATCH("protocol", "enable_ipv6")) {
        pconfig->enable_ipv6 = (strcmp(value, "true") == 0);
    } else if (MATCH("user", "name")) {
        pconfig->name = strdup(value); // Duplicate string to store it safely
    } else if (MATCH("user", "email")) {
        pconfig->email = strdup(value);
    } else {
        return 0; /* Unknown section or key; return 0 if you want to flag an error */
    }
    
    return 1; /* Return 1 to signal success and continue parsing */
}

int main(int argc, char* argv[]) {
    const char *filename = argv[1];

    configuration config;
    
    // Initialize default values
    config.version = 0;
    config.enable_ipv6 = false;
    config.name = NULL;
    config.email = NULL;

    // Invoke the parser by passing the file path, callback handler, and context struct
    if (ini_parse(filename, handler, &config) < 0) {
        printf("Error: Can't load or parse '%s'\n", filename);
        return 1;
    }

    // Print out the parsed values to verify they mapped correctly
    printf("Config loaded successfully:\n");
    printf("  Protocol Version: %d\n", config.version);
    printf("  IPv6 Enabled:     %s\n", config.enable_ipv6 ? "true" : "false");
    printf("  User Name:        %s\n", config.name ? config.name : "N/A");
    printf("  User Email:       %s\n", config.email ? config.email : "N/A");

    // Clean up allocated memory
    free((void*)config.name);
    free((void*)config.email);

    return 0;
}

