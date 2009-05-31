# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	2.3.2
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/
PKGNAMESUFFIX=	-mysql${MYSQL_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

CONFLICTS=	${PORTNAME}*-1.*
NO_LATEST_LINK=	yes

NOT_FOR_ARCHS=	amd64 sparc64
NOT_FOR_ARCHS_REASON_amd64=	Fails to compile
NOT_FOR_ARCHS_REASON_sparc64=	Fails to compile

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

PORTDOCS=	*
PORTEXAMPLES=	*

PORTSCOUT=	limit:^2\.

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${DOCSDIR}/html)
	@${MKDIR} ${DOCSDIR}/pdf
	@(cd ${WRKSRC}/doc/pdf && ${COPYTREE_SHARE} . ${DOCSDIR}/pdf)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
