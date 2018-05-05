# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	cider
PORTVERSION=	1.b1
PORTREVISION=	8
CATEGORIES=	cad
MASTER_SITES=	LOCAL/mita
DISTNAME=	cider1b1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mixed-level circuit and device simulator (includes SPICE3)

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06
BROKEN_aarch64=		fails to link: missing sbrk
BROKEN_powerpc64=	fails to compile: ccache: cc: FreeBSD: No such file or directory

CONFLICTS=	spice-[0-9]*
WRKSRC=		${WRKDIR}/sim
USE_XORG=	xt xaw xmu

OPTIONS_DEFINE=	EXAMPLES

CFLAGS+=	-Wno-return-type

pre-patch:
	@${CP} -f ${WRKSRC}/spice/common/lib/helpdir/spice.txt \
		${WRKSRC}/cider/common/lib/helpdir/spice.txt

post-patch:
	@${LN} -fs ../../../spice/common/util/makelib.sh \
		${WRKSRC}/cider/common/util
	@${LN} -fs ../../../../spice/common/src/lib/sparse/spdefs.h \
		${WRKSRC}/cider/common/src/include
	@${CP} -f ${FILESDIR}/Makefile.spice ${WRKSRC}/spice/common/Makefile
	@${CP} -f ${FILESDIR}/Makefile.cider ${WRKSRC}/cider/common/Makefile
	@${CP} -f ${FILESDIR}/FreeBSD ${WRKSRC}/spice/common/conf
	@${CP} -f ${FILESDIR}/FreeBSD ${WRKSRC}/cider/common/conf

do-build:
	@(cd ${WRKSRC}/spice/common && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}) && \
	    (cd ${WRKSRC}/cider/common && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/spice3/helpdir \
		${STAGEDIR}${DATADIR}/spice3/scripts \
		${STAGEDIR}${DATADIR}/cider/helpdir \
		${STAGEDIR}${DATADIR}/cider/scripts
	${INSTALL_PROGRAM} ${WRKSRC}/cider/FreeBSD/obj/bin/cider \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cider/common/doc/cider.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/cider/common/lib/helpdir/*.txt \
		${STAGEDIR}${DATADIR}/cider/helpdir
	${INSTALL_SCRIPT} ${WRKSRC}/cider/common/lib/scripts/dev* \
		${STAGEDIR}${DATADIR}/cider/scripts
	(cd ${WRKSRC}/spice/FreeBSD/obj/bin && ${INSTALL_PROGRAM} \
		spice3 nutmeg sconvert help proc2mod multidec \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/spice/common/man/man1 && ${INSTALL_MAN} nutmeg.1 \
		sconvert.1 spice.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${STAGEDIR}${MANPREFIX}/man/man1 && \
		${LN} -s spice.1 spice3.1)
	${INSTALL_MAN} ${WRKSRC}/spice/common/man/man3/mfb.3 \
		${STAGEDIR}${MANPREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/spice/common/man/man5/mfbcap.5 \
		${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/spice/common/lib/helpdir/spice.txt \
		${STAGEDIR}${DATADIR}/spice3/helpdir
	(cd ${WRKSRC}/spice/common/lib && ${INSTALL_DATA} news mfbcap \
		${STAGEDIR}${DATADIR}/spice3)
	${INSTALL_SCRIPT} ${WRKSRC}/spice/common/lib/scripts/s* \
		${STAGEDIR}${DATADIR}/spice3/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/spice/common/lib/scripts/spinit \
		${STAGEDIR}${DATADIR}/cider/scripts
do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/spice3
	${INSTALL_DATA} ${WRKSRC}/spice/common/examples/*.cir \
		${STAGEDIR}${EXAMPLESDIR}/spice3
	cd ${WRKSRC}/cider/common/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
