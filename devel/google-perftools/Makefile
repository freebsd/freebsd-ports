# New ports collection makefile for:	google-sparsehash
# Date created:				07 January 2007
# Whom:					Yuri Victorovich <yuri@tsoft.com>
#
# $FreeBSD$
#

PORTNAME=	google-perftools
PORTVERSION=	0.94
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME}

MAINTAINER=	yuri@tsoft.com
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-build:
	@${ECHO}
	@${ECHO} "Be aware that some of the self tests are known to fail."
	@${ECHO} "Run 'make check' and try to fix that. Thanks!"
	@${ECHO}

# four of the tests are known to fail on 7.0, uncomment this as soon as this is fixed
#regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
# src/stacktrace.cc:81:5: #error Cannnot calculate stack trace: need libunwind (see INSTALL file)
BROKEN=	Does not build, cannnot calculate stack trace: need libunwind (see INSTALL file)
.endif

.include <bsd.port.post.mk>
