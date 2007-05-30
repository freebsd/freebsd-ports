# New ports collection makefile for:	xapian-bindings
# Date created:		2007-05-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-bindings
PORTVERSION=	1.0.0
CATEGORIES=	databases java
MASTER_SITES=	http://www.oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	gslin@gslin.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

RUN_DEPENDS=	xapian-core>=1.0.0:${PORTSDIR}/databases/xapian-core
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFIGURE_ARGS=	--without-csharp --without-java --without-ruby --without-tcl
GNU_CONFIGURE=	yes

OPTIONS=	PHP "Enable PHP binding" on \
		PYTHON "Enable Python binding" off

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_PHP)
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=	BINDING_PHP="@comment "
.else
CONFIGURE_ARGS+=	--with-php
PLIST_SUB+=	BINDING_PHP=""
USE_PHP=	yes
.endif

.ifdef(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=	BINDING_PYTHON=""
USE_PYTHON=	yes
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	BINDING_PYTHON="@comment "
.endif

post-install:
.ifdef(NOPORTDOCS)
	${RM} -fr ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
