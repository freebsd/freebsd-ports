# New ports collection makefile for:	icmake
# Date created:		March 4, 2009
# Whom:	      		Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icmake
PORTVERSION=	7.12.5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	An Intelligent C-like Maker

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		icmake.1 icmbuild.1 icmstart.1
MAN7=		icmstart.rc.7
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/icm_bootstrap \
		${WRKSRC}/icm_install \
		${WRKSRC}/scripts/convert
	@${REINPLACE_CMD} -e 's|sed|gsed|g' \
		${WRKSRC}/scripts/conversions \
		${WRKSRC}/scripts/convert
	@${REINPLACE_CMD} -e 's|"usr/bin"|"bin"| ; \
		s|"usr/share/icmake"|"share/icmake-${PORTVERSION}"| ; \
		s|"usr/share/man"|"man"| ; \
		s|"usr/lib/icmake"|"lib/icmake-${PORTVERSION}"| ; \
		s|"usr/share/doc/icmake"|"share/doc/icmake-${PORTVERSION}"| ; \
		s|"usr/share/doc/icmake-doc"|"share/doc/icmake-${PORTVERSION}/doc"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e '\
		s|"ar"|"${AR}"| ; \
		s|"rsv"|"${ARFLAGS}"| ; \
		s|"gcc"|"${CC}"| ; \
		s|"-c -Wall -O2|"-c ${CFLAGS}| ; \
		s|"gzip"|"${GZIP_CMD}"| ; \
		s|"cp"|"${CP}"| ; \
		s|"mkdir"|"${MKDIR}"| ; \
		s|"rm"|"${RM}"| ; \
		s|"strip"|"${STRIP_CMD}"|' \
		${WRKSRC}/def/programs
	@${REINPLACE_CMD} -e '\
		s|gcc|${CC}| ; \
		s|-O2 -g -Wall|${CFLAGS}| ; \
		s|cp -r|cp -R|' \
		${WRKSRC}/icm_bootstrap \
		${WRKSRC}/icm_install

do-build:
	cd ${WRKSRC} && ./icm_bootstrap ${PREFIX}

do-install:
	cd ${WRKSRC} && ./icm_install strip progs
	cd ${WRKSRC} && ./icm_install scripts
	cd ${WRKSRC} && ./icm_install skel
	cd ${WRKSRC} && ./icm_install etc
.if !defined(NO_INSTALL_MANPAGES)
	cd ${WRKSRC} && ./icm_install man
.endif
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ./icm_install doc
	cd ${WRKSRC} && ./icm_install docdoc
.endif

.include <bsd.port.mk>
