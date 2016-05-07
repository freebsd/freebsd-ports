# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	omniNotify
PORTVERSION=	2.1.01
#It' snapshot of development version actually
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.stasyan.com/devel/distfiles/
DISTNAME=	omniNotify-2-latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CORBA Notification Service (CosNotification) for omniORB

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libomniORB4.so:devel/omniORB-4.1
# parts of omniORB4-4.1 source tree is required to build
BUILD_DEPENDS=	${NONEXISTENT}:devel/omniORB-4.1:patch

WRKSRC=		${WRKDIR}/${PORTNAME}
OMNIORB_WRKSRC=	`cd ${PORTSDIR}/devel/omniORB-4.1 && ${MAKE} -V WRKSRC`

USES=		gmake python
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-omniorb=${LOCALBASE}
OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	${REINPLACE_CMD} -Ee 's|-O2|${CFLAGS}|' \
		${WRKSRC}/mk/beforeauto.mk.in
	cd ${OMNIORB_WRKSRC} && ${FIND} idl | ${CPIO} --quiet -pdum ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notifd \
		${STAGEDIR}${PREFIX}/lib/lib*.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! ( -name \.cvsignore -o -name *\.orig )"

.include <bsd.port.mk>
