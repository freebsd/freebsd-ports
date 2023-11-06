PORTNAME=	star
CATEGORIES=	archivers

COMMENT=	Unique standard tape archiver with many enhancements
WWW=		https://cdrtools.sourceforge.net/private/star.html

PORTDOCS=	README* STARvsGNUTAR

OPTIONS_DEFINE+=DOCS GNUTAR
OPTIONS_SUB=	yes
GNUTAR_DESC=	Install a gnutar binary

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	mt \
		rmt \
		star \
		star_sym \
		strar

# these are shipped in archivers/tartest
post-install:
	${RM} -r ${STAGEDIR}${DOCSDIR}/testscripts

.include "${MASTERDIR}/Makefile.master"
