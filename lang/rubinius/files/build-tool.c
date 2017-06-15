/* LLVM wrapper script invokes the actual binary based on the argv[0]
 * which rubinius messes up, by calling clang39 as cc, and thus breaking
 * the LLVM wrapper. This hack workarounds this limitation, by invoking 
 * LLVM wrapper script with expected argv[0]
 */

#include <string.h>
#include <unistd.h>

#define PATH_CC "%%CC%%"
#define PATH_CXX "%%CXX%%"

int
main(int argc, char** argv)
{
	char* basename = strrchr(argv[0] , '/');
	
	if(NULL == basename)
		basename = argv[0];
	else
		basename++;

	if( !strcmp(basename, "cc"))
		execv(PATH_CC, argv);
	else if( !strcmp(basename, "c++")) 
		execv(PATH_CXX, argv);
	else
		return 0;
}
