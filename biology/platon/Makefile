# New ports collection makefile for:	platon
# Date created:		1999-04-22
# Whom:			Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	platon
PORTVERSION=	2007.01.09
PORTREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	ftp://xraysoft.chem.uu.nl/pub/unix/
DISTNAME=	platon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for viewing molecular/crystallographic structures

# PLATON may be used free of charge by the academic community under
# the condition that it is not redistributed for a current & fresh copy.
# There is a charge of US$ 5000 for commercial users.
RESTRICTED=	free for academic, US$ 5000 for commercial users

USE_XORG=	x11
USE_FORTRAN=	yes

# This port only has snapshot archive
IGNOREFILES=	platon.tar.gz

SAMPLES=	azt.dat bucky.spf c476.spf c540.cart3d check.def cubane.spf \
		cyto.spf ml.pdb s810c.cif s913a.res sucrose.spf
TESTDATADIR=	ABSORB_EXAMPLE ABSTOMPA_EXAMPLE ABSTOMPA_TEST ADDSYM_EXAMPLE \
		ASYM_EXAMPLE DELABS_EXAMPLE MULABS_EXAMPLE PSICOR_EXAMPLE \
		SQUEEZE_EXAMPLE

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=	/usr/libexec/elf/ld: platon.o: .got subsegment exceeds 64K (size 88552)
.endif

pre-patch:
	(cd ${WRKDIR}/${DISTNAME} ; ${GUNZIP_CMD} platon.f.Z xdrvr.c.gz)

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s+%%LOCALBASE%%+${LOCALBASE}+"  ${WRKSRC}/Makefile

pre-install:
	${STRIP_CMD} ${WRKDIR}/${DISTNAME}/platon
	${RM} -f ${PREFIX}/bin/pluton
	${RM} -rf ${PREFIX}/share/doc/platon
	${MKDIR} ${PREFIX}/share/doc/platon
	${RM} -rf ${PREFIX}/share/doc/platon/TEST
	${MKDIR} ${PREFIX}/share/doc/platon/TEST

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/platon ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/platon ${PREFIX}/bin/pluton
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README* \
		${PREFIX}/share/doc/platon
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/VALIDATION.DOC \
		${PREFIX}/share/doc/platon
	for file in ${SAMPLES} ; do \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$${file} \
			${PREFIX}/share/doc/platon ; \
	done
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/platon_html.tar.gz \
		${PREFIX}/share/doc/platon
	for dirs in ${TESTDATADIR} ; do \
		${MKDIR} ${PREFIX}/share/doc/platon/TEST/$${dirs} && \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TEST/$${dirs}/* \
			${PREFIX}/share/doc/platon/TEST/$${dirs} ; \
	done

.include <bsd.port.post.mk>
