# Created by: Kapil Chowksey <kchowksey@hss.hns.com>
# $FreeBSD$

PORTNAME=	gindent
PORTVERSION=	2.2.12
CATEGORIES=	devel
MASTER_SITES=	GNU/indent
DISTNAME=	indent-${PORTVERSION}

MAINTAINER=	moritz@schmi.tt
COMMENT=	GNU indent

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase:ldflags makeinfo
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
	# XXX: Would be nice to use "configure --htmldir" or something similar
	# to install this document into an appropriate directory automatically.
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/doc/indent/indent.html ${STAGEDIR}${DOCSDIR}
	${RM} -r ${STAGEDIR}${PREFIX}/doc

.include <bsd.port.mk>
