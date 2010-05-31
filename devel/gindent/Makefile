# ex:ts=8
# New ports collection makefile for:   indent
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# $FreeBSD$
#

PORTNAME=	gindent
PORTVERSION=	2.2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	indent
DISTNAME=	indent-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU indent

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DBERKELEY_DEFAULTS=1" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--program-prefix=g
MAKE_JOBS_UNSAFE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		gindent.1
INFO=		indent

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/indent.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
