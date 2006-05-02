# Ports collection makefile for:	ace
# Date created:				5 January 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ace
PORTVERSION=	5.5.1
CATEGORIES=	devel
MASTER_SITES=	ftp://deuce.doc.wustl.edu/pub/previous_versions/ \
		http://deuce.doc.wustl.edu/old_distribution/ \
		http://www.navicon.dk/mirrors/ace/deuce.doc.wustl.edu/old_distribution/
DISTNAME=	ACE-${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org

COMMENT=	The Adaptive Communication Environment for C++

CONFLICTS=	ace+tao-5*

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-transform-name s,^,ace-,
USE_GNOME=	pkgconfig

WRKSRC=		${WRKDIR}/ACE_wrappers
BUILD_WRKSRC=	${WRKSRC}/objdir
INSTALL_WRKSRC=	${BUILD_WRKSRC}
NOT_FOR_ARCH=	sparc64

MAN1=		ace-gperf.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not support
.endif

.if ${OSVERSION} > 700015
EXTRA_PATCHES=	${FILESDIR}/extra-ace-OS_NS_netdb.inl
.endif

post-extract:
	@${MKDIR} ${BUILD_WRKSRC}

do-configure:
	@cd ${BUILD_WRKSRC}; \
	${CONFIGURE_ENV} ../${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include <bsd.port.post.mk>
