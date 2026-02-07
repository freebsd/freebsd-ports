/***************************************************************************
 *  Description:
 *      Wrapper to turn emboss commands into subcommands.  The emboss suite
 *      contains executables that conflict with multiple other software
 *      packages and therefore cannot be safely installed directly under a
 *      standard prefix.  This wrapper can be installed under the standard
 *      PATH and used to to execute emboss commands installed under a
 *      private prefix, without altering PATH, activating a special
 *      environment, opening a container, etc.  This sub-command paradigm
 *      is already familiar to bioinformaticians thanks to other suites
 *      like samtools, bedtools, etc.
 *
 *      Example:
 *
 *          emboss seqret args
 *
 *      instead of one of the following:
 *
 *          prefix/bin/seqret args
 *
 *          env PATH=prefix/bin:$PATH seqret args
 *
 *          conda activate emboss
 *          seqret args
 *
 *  Arguments:
 *      The full emboss command you would use if it were in PATH.
 *
 *  Compile with EMBOSS_PREFIX set to the parent of the bin directory
 *  containing the emboss binaries.
 *
 *  History: 
 *  Date        Name        Modification
 *  2021-09-13  Jason Bacon Begin
 ***************************************************************************/

#include <stdio.h>
#include <sysexits.h>
#include <limits.h>
#include <unistd.h>

#ifndef EMBOSS_PREFIX
#define EMBOSS_PREFIX   "/usr/local/emboss"
#endif

int     main(int argc,char *argv[])

{
    char    cmd[PATH_MAX + 1];
    
    if ( argc < 2 )
    {
        fprintf(stderr, "Usage: %s emboss-command [args]\n", argv[0]);
        return EX_USAGE;
    }

    snprintf(cmd, PATH_MAX, "%s/bin/%s", EMBOSS_PREFIX, argv[1]);
    execv(cmd, argv + 1);
}
