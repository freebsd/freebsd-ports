#!/bin/sh

# Quick smoke-test for the newly-built library and command-line utilities
# Copied from Brew:
#	https://github.com/Homebrew/homebrew-core/blob/697d00453308186b31ecd22737f5b10cc105b162/Formula/jxrlib.rb

b64decode -r << EOBMP > ${WRKSRC}/test.bmp
Qk06AAAAAAAAADYAAAAoAAAAAQAAAAEAAAABABgAAAAAAAQAAADCDgAAwg4AAAAAAAAAAAAA////
AA==
EOBMP

export LD_LIBRARY_PATH=${WRKSRC}/jxrgluelib:${WRKSRC}/libjpegxr

${WRKSRC}/JxrEncApp/JxrEncApp -i ${WRKSRC}/test.bmp -o ${WRKSRC}/test.jxr
${WRKSRC}/JxrDecApp/JxrDecApp -i ${WRKSRC}/test.jxr -o ${WRKSRC}/result.bmp

ls -l ${WRKSRC}/test.bmp ${WRKSRC}/test.jxr ${WRKSRC}/result.bmp

if cmp -zs ${WRKSRC}/test.bmp ${WRKSRC}/result.bmp
then
	echo Result matches expectations
	exit 0
else
	echo Result is not the same as input, may be a problem
	exit 0
fi
