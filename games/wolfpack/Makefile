# New ports collection makefile for:    wolfpack
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	wolfpack
PORTVERSION=	4.3.22
CATEGORIES=	games
MASTER_SITES=	SF/empserver/empserver/Empire%20Server%20v${PORTVERSION}
DISTNAME=	empire-${PORTVERSION}

MAINTAINER=	johans@stack.nl
COMMENT=	Long term multiplayer strategy game

MAKEFILE=	GNUmakefile
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
BINDIR=		${PREFIX}/lib/${PORTNAME}
CONFIGURE_ARGS+=	--bindir=${BINDIR} --sbindir=${BINDIR}

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

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	@${LN} -s ${BINDIR}/emp_server ${PREFIX}/bin/emp_server
	@${LN} -s ${BINDIR}/empire ${PREFIX}/bin/emp_client
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
