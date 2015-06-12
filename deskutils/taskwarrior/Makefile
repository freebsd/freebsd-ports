# Created by: gahr
# $FreeBSD$

PORTNAME=	taskwarrior
PORTVERSION=	2.4.4
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/
DISTNAME=	task-${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Feature-rich command-line todo list manager

LICENSE=	MIT

OPTIONS_DEFINE=GNUTLS
OPTIONS_DEFAULT=GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_GnuTLS=TRUE

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang36:${PORTSDIR}/lang/clang36
CPP=	${LOCALBASE}/bin/clang-cpp36
CC=	${LOCALBASE}/bin/clang36
CXX=	${LOCALBASE}/bin/clang++36
.endif

WRKSRC=		${WRKDIR}/task-${PORTVERSION}

USES=		cmake:outsource shebangfix
SHEBANG_FILES=	scripts/*/*.pl \
		scripts/*/*.rb \
		scripts/*/*.py \
		doc/rc/refresh
CMAKE_ARGS+=	-DTASK_DOCDIR:STRING=${DATADIR:S/${PREFIX}\///} \
   		-DTASK_MAN1DIR:STRING=man/man1 \
		-DTASK_MAN5DIR:STRING=man/man5

.include <bsd.port.mk>
