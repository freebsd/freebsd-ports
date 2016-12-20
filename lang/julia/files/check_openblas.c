#include <string.h>

char* openblas_get_config(void);

int main()
{
    if (strstr(openblas_get_config(), "USE64BITINT") == NULL)
        return 1;
    return 0;
}
