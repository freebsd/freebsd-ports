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

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-DBERKELEY_DEFAULTS=1

INFO=		indent

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/indent.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
