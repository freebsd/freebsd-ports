PORTNAME=	star
CATEGORIES=	archivers

COMMENT=	Unique standard tape archiver with many enhancements

PORTDOCS=	README* STARvsGNUTAR

OPTIONS_DEFINE+=DOCS GNUTAR TARTEST
OPTIONS_SUB=	yes
GNUTAR_DESC=	Install a gnutar binary
TARTEST_DESC=	Install tartest and test scripts
TARTEST_VARS=	COMPONENTS+=tartest

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	mt \
		rmt \
		star \
		star_sym \
		strar

.include "${MASTERDIR}/Makefile.master"
