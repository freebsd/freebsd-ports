# New ports collection makefile for:	google-sparsehash
# Date created:				07 January 2007
# Whom:					Yuri Victorovich <yuri@tsoft.com>
#
# $FreeBSD$
#

PORTNAME=	google-perftools
PORTVERSION=	0.93
CATEGORIES=	devel
MASTER_SITES=	http://google-perftools.googlecode.com/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME}

MAINTAINER=	yuri@tsoft.com
COMMENT=	Fast, mutli-threaded malloc() and nifty performance analysis tools

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
	@${ECHO} "Be aware that one of the self tests is known to fail."
	@${ECHO} "Run 'make check' and try to fix that. Thanks!"
	@${ECHO}

# one of the tests is known to fail, uncomment this as soon as it is fixed
#regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
# src/stacktrace.cc:81:5: #error Cannnot calculate stack trace: need libunwind (see INSTALL file)
BROKEN=	Does not build on amd64, cannnot calculate stack trace: need libunwind (see INSTALL file)
.endif

.include <bsd.port.post.mk>
