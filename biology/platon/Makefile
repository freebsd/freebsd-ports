# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	platon
PORTVERSION=	2015.03.30
CATEGORIES=	biology
MASTER_SITES=	http://www.platonsoft.nl/spek/xraysoft/unix/
DISTNAME=	platon
DIST_SUBDIR=	platon/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for viewing molecular/crystallographic structures

BROKEN=		checksum mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

# PLATON may be used free of charge by the academic community under
# the condition that it is not redistributed for a current & fresh copy.
# There is a charge of US$ 5000 for commercial users.
NO_CDROM=	free for academic, US$ 5000 for commercial users

USES=		fortran
USE_XORG=	x11

SAMPLES=	azt.dat bucky.spf c476.spf c540.cart3d check.def cubane.spf \
		cyto.spf ml.pdb s810c.cif s913a.res sucrose.spf
TESTDATADIR=	ABSORB_EXAMPLE ABSTOMPA_EXAMPLE ABSTOMPA_TEST ADDSYM_EXAMPLE \
		ASYM_EXAMPLE MULABS_EXAMPLE PSICOR_EXAMPLE SQUEEZE_EXAMPLE

OPTIONS_DEFINE=	DOCS

MAKEFILE=	${FILESDIR}/Makefile

pre-patch:
	${GUNZIP_CMD} ${WRKSRC}/platon.f.gz ${WRKSRC}/xdrvr.c.gz

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/platon \
		${STAGEDIR}${PREFIX}/bin
	${LN} -fs platon ${STAGEDIR}${PREFIX}/bin/pluton
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${WRKDIR}/${DISTNAME}/README* ${STAGEDIR}${DOCSDIR}/
	${MV} ${SAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/
	${MV} ${WRKSRC}/platon_html.tar.gz \
		${STAGEDIR}${DOCSDIR}
	${MV} ${WRKSRC}/TEST ${STAGEDIR}${DOCSDIR}/
	${FIND} ${STAGEDIR}${DOCSDIR} -type f -print0 |	\
		${XARGS} -0 ${CHMOD} ${_SHAREMODE}

.include <bsd.port.mk>
