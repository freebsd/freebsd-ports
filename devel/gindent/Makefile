# Created by: Kapil Chowksey <kchowksey@hss.hns.com>
# $FreeBSD$

PORTNAME=	gindent
PORTVERSION=	2.2.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	indent
DISTNAME=	indent-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU indent

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DBERKELEY_DEFAULTS=1
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--program-prefix=g
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		indent

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/indent.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
