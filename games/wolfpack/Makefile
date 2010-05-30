# New ports collection makefile for:    wolfpack
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	wolfpack
PORTVERSION=	4.3.26
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	empserver/${DISTNAME}
DISTNAME=	empire-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Long term multiplayer strategy game

MAKEFILE=	GNUmakefile
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
BINDIR=		${PREFIX}/lib/${PORTNAME}
VARDIR=		${PREFIX}/var/${PORTNAME}
CONFIGURE_ARGS+=	--bindir=${BINDIR} --sbindir=${BINDIR}

USERS=		wolfpack
GROUPS=		wolfpack

USE_RC_SUBR=	wolfpack
SUB_FILES+=	pkg-message

MAN6=		empire.6 emp_server.6 empdump.6 empsched.6 \
		fairland.6 files.6 pconfig.6

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e '/^econfig/,/^$$/s|/empire|/${PORTNAME}|' \
		${WRKSRC}/Make.mk ${WRKSRC}/sources.mk
.if ${ARCH} == "sparc64"
	${REINPLACE_CMD} -e '/ucontext\.h/ { h; s|ucontext|sys/types|; G; }' \
		${WRKSRC}/src/lib/lwp/lwpint.h
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	@${LN} -s ${BINDIR}/emp_server ${PREFIX}/bin/emp_server
	@${LN} -s ${BINDIR}/empire ${PREFIX}/bin/emp_client
	@${PREFIX}/lib/wolfpack/pconfig > ${ETCDIR}/econfig.orig
	@${CHOWN} -R ${USERS}:${GROUPS} ${DATADIR} ${ETCDIR} ${VARDIR}
	@${CHMOD} -R u+w,o-rx ${DATADIR} ${ETCDIR} ${VARDIR}
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
