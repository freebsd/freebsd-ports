# New ports collection makefile for:	opencc
# Date created:				28 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	opencc
PORTVERSION=	0.2.0
CATEGORIES=	chinese converters
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lichray@gmail.com
COMMENT=	Open Chinese Convert library and utilities

LICENSE=	ASL

MAN1=	opencc.1 opencc_dict.1

USE_CMAKE=	yes
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CMAKE_ARGS+=	-DENABLE_GETTEXT=On
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(NOPORTDATA)
IGNORE=		thesaurus are required, undefine NOPORTDATA
.endif

post-patch:
	@${REINPLACE_CMD} -e 's@/usr/local@${LOCALBASE}@g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc: signal 11
.endif

.include <bsd.port.post.mk>
