PORTNAME=	ved
CATEGORIES=	editors

COMMENT=	Visual editor (easy to learn, fast, and lean)
WWW=		https://schilytools.sourceforge.net/ved.html

OPTIONS_DEFINE=	DOCS

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	ved

post-install-DOCS-off:
	${RM} ${STAGEDIR}share/doc/vedsheet.*
	${RM} ${STAGEDIR}share/man/help/ved.help.gz

.include "${MASTERDIR}/Makefile.master"
