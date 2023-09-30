PORTNAME=	wolfpack
PORTVERSION=	4.4.1
CATEGORIES=	games
MASTER_SITES=	SF/empserver/${DISTNAME}
DISTNAME=	empire-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Long term multiplayer strategy game
WWW=		http://www.wolfpackempire.com/

LICENSE=	GPLv3+

MAKEFILE=	GNUmakefile
USES=		gmake groff perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
BINDIR=		lib/${PORTNAME}
CONFIGURE_ARGS=	--bindir=${PREFIX}/${BINDIR} --sbindir=${PREFIX}/${BINDIR}

CONFLICTS_INSTALL=	empire

USERS=		wolfpack
GROUPS=		wolfpack

USE_RC_SUBR=	wolfpack
SUB_FILES+=	pkg-message

post-patch:
	${REINPLACE_CMD} -e '/^econfig/,/^$$/s|/empire|/${PORTNAME}|' \
		${WRKSRC}/Make.mk ${WRKSRC}/sources.mk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DATADIR}
	${LN} -s ../${BINDIR}/emp_server ${STAGEDIR}${PREFIX}/bin/emp_server
	${LN} -s ../${BINDIR}/empire ${STAGEDIR}${PREFIX}/bin/emp_client
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${STAGEDIR}${PREFIX}/lib/wolfpack/pconfig > \
		${STAGEDIR}${ETCDIR}/econfig.sample

.include <bsd.port.mk>
