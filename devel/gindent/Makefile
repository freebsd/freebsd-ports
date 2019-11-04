# Created by: Kapil Chowksey <kchowksey@hss.hns.com>
# $FreeBSD$

PORTNAME=	gindent
PORTVERSION=	2.2.10
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	GNU/indent
DISTNAME=	indent-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU indent

OPTIONS_DEFINE=	DOCS NLS

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DBERKELEY_DEFAULTS=1
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--program-prefix=g
MAKE_JOBS_UNSAFE=	yes

NLS_USES=	gettext
OPTIONS_SUB=	yes
NLS_CONFIGURE_OFF=	--disable-nls

INFO=		indent

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/indent.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
