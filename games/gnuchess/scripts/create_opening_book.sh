#!/bin/sh

DISTDIR=$1
WRKSRC=$2

[ -f ${WRKSRC}/src/book.dat ] && exit 0

builtin echo -e "\nCreating opening book for gnuchess...\n"

cp ${DISTDIR}/book_1.01.pgn.gz ${WRKSRC}/src/book.pgn.gz

cd ${WRKSRC}/src && gunzip -f book.pgn.gz

./gnuchess << END
book add book.pgn
quit
END

[ $? = 0 ] && builtin echo -e "\nBook successfully created!\n"
