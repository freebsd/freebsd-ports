# New ports collection makefile for:	CHICKEN
# Date created:				31 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	chicken
PORTVERSION=	3.2.0
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.call-with-current-continuation.org/ \
				http://chicken.wiki.br/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A Scheme-to-C compiler

USE_GMAKE=	yes
MAKE_ARGS+=	PLATFORM=bsd PREFIX=${PREFIX} TOPMANDIR="${PREFIX}/man"
PLATFORM=	bsd

OPTIONS=	PCRE "Enable PCRE support" off

MAN1=		chicken-bug.1 chicken-profile.1 chicken-setup.1 chicken.1 csc.1 csi.1
INFO=		chicken
INFODIR=	${PREFIX}/${INFO_PATH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
#BROKEN=		coredump during build on ia64
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
USE_HOST_PCRE=${PREFIX}/lib/libpcre.so
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ENV+=	ac_cv_header_pcre_h=no
.endif

MAKE_FLAGS+=	HOST=${HOST} PREFIX=${PREFIX} PLATFORM=${PLATFORM} INFODIR=${PREFIX}/info

post-patch:
	${MV}  ${WRKSRC}/apply-hack.x86.s ${WRKSRC}/apply-hack.i386.s
#	@${REINPLACE_CMD} -e 's/\(install-data-am: \)install-data-local/\1/' \
#		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE NEWS README \
		${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}/benchmarks
	${CP} -R ${WRKSRC}/benchmarks/* ${EXAMPLESDIR}/benchmarks/
.endif

.include <bsd.port.post.mk>
