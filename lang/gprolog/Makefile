# New ports collection makefile for:   gprolog
# Date created:        30 June 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	gprolog
PORTVERSION=	1.2.18
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_DEBIAN} ftp://ftp.inria.fr/INRIA/Projects/contraintes/gprolog/:doc
MASTER_SITE_SUBDIR=	pool/main/g/${PORTNAME}
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	manual.pdf.gz:doc manual-html.tar.gz:doc
.endif
DIST_SUBDIR=	gprolog
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	vs@FreeBSD.org
COMMENT=	A free Prolog compiler

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}.orig/src/src

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}" \
		--with-doc-dir=none \
		--with-examples-dir="${EXAMPLESDIR}"

PLIST_SUB+=	GPROLOG_VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
CONFIGURE_ARGS+=--disable-fast-call
.endif

post-extract:
	@${CP} ${PORTSDIR}/Templates/config.sub ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/EnginePl/machine.c

post-install:
.	if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${DOCSDIR} && ${GZIP_CMD} -cd ${_DISTDIR}/manual.pdf.gz >manual.pdf
	@cd ${DOCSDIR} && ${TAR} zxf ${_DISTDIR}/manual-html.tar.gz
.	endif

.include <bsd.port.post.mk>
