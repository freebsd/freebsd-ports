# New ports collection makefile for:    sis
# Date created:         10 October 1997
# Whom:                 volf@oasis.IAEhv.nl
#
# $FreeBSD$
#

PORTNAME=		sis
PORTVERSION=		1.2.1
CATEGORIES=		cad
MASTER_SITES=		ftp://ic.eecs.berkeley.edu/pub/Sis/
DISTNAME=		${PORTNAME}-1.2
EXTRACT_SUFX=		.tar.Z

PATCH_SITES=		ftp://ic.eecs.berkeley.edu/pub/Sis/
PATCHFILES=		sis-1.2.patch1.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=		volf@oasis.IAEhv.nl

USE_XLIB=		yes
MAKEFILE=		Makefile.FreeBSD
MAN1=			espresso.1 jedi.1 nova.1 sis.1 sred.1 stamina.1 \
			vst2blif.1 xsis.1
MAN5=			espresso.5 pla.5

pre-build: ${WRKSRC}/Makefile.FreeBSD

${WRKSRC}/Makefile.FreeBSD:
	${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sis/sis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/jedi/jedi ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sred/sred ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/stamina/bin/stamina ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nova/nova ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/espresso/espresso ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vst2blif/vst2blif ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/blif2vst/blif2vst ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xsis/xsis ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/espresso/espresso.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/jedi/jedi.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nova/nova.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sis/sis_lib/help/sis.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sred/sred.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/stamina/stamina.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/vst2blif/vst2blif.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/xsis/xsis.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/espresso/espresso.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/espresso/pla.5 ${PREFIX}/man/man5
	${MKDIR} ${PREFIX}/lib/sis
	${TAR} -C ${WRKSRC}/sis -cf - sis_lib | \
		${TAR} -C ${PREFIX}/lib/sis --unlink -xf -
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/SIS_paper.ps ${PREFIX}/lib/sis
	${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES-1.2 ${PREFIX}/lib/sis
	${GZIP_CMD} ${PREFIX}/lib/sis/SIS_paper.ps
.endif
	${CHOWN} -R bin:bin ${PREFIX}/lib/sis

.include <bsd.port.mk>
