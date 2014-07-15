# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	omniNotify
PORTVERSION=	2.1.01
#It' snapshot of development version actually
CATEGORIES=	devel python
MASTER_SITES=	http://www.stasyan.com/devel/distfiles/
DISTNAME=	omniNotify-2-latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CORBA Notification Service (CosNotification) for omniORB

LIB_DEPENDS=	libomniORB4.so:${PORTSDIR}/devel/omniORB
RUN_DEPENDS=	omniidl:${PORTSDIR}/devel/omniORB
# parts of omniORB4 source tree is required to build
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/omniORB:patch

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
OMNIORB_WRKSRC!=	cd ${.CURDIR}/../omniORB && ${MAKE} -V WRKSRC

USES=		gmake
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-omniorb=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${OMNIORB_WRKSRC} && ${FIND} idl | ${CPIO} --quiet -pdum ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -Ee 's/-O2/${CFLAGS}/' \
		${WRKSRC}/mk/beforeauto.mk.in

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR} "! ( -name \.cvsignore -o -name *\.orig )"
.endif

.include <bsd.port.post.mk>
