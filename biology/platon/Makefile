# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	platon
PORTVERSION=	2013.12.12
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.cryst.chem.uu.nl/spek/xraysoft/unix/
DISTNAME=	platon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for viewing molecular/crystallographic structures

# PLATON may be used free of charge by the academic community under
# the condition that it is not redistributed for a current & fresh copy.
# There is a charge of US$ 5000 for commercial users.
RESTRICTED=	free for academic, US$ 5000 for commercial users

USES=		fortran
USE_XORG=	x11

# This port only has snapshot archive
IGNOREFILES=	platon.tar.gz

SAMPLES=	azt.dat bucky.spf c476.spf c540.cart3d check.def cubane.spf \
		cyto.spf ml.pdb s810c.cif s913a.res sucrose.spf
TESTDATADIR=	ABSORB_EXAMPLE ABSTOMPA_EXAMPLE ABSTOMPA_TEST ADDSYM_EXAMPLE \
		ASYM_EXAMPLE MULABS_EXAMPLE PSICOR_EXAMPLE SQUEEZE_EXAMPLE

.include <bsd.port.pre.mk>

pre-patch:
	(cd ${WRKDIR}/${DISTNAME} ; ${GUNZIP_CMD} platon.f.gz xdrvr.c.gz)

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s+%%LOCALBASE%%+${LOCALBASE}+"  ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/platon \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s platon ${STAGEDIR}${PREFIX}/bin/pluton
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README* ${STAGEDIR}${DOCSDIR}
.for f in ${SAMPLES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/platon_html.tar.gz \
		${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/TEST
.for d in ${TESTDATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/TEST/$d
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TEST/$d/* \
		${STAGEDIR}${DOCSDIR}/TEST/$d
.endfor

.include <bsd.port.post.mk>
