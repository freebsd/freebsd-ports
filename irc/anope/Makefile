# New ports collection makefile for:	anope
# Date created:		13/04/2004
# Whom:			mat
#
# $FreeBSD$
#

PORTNAME=	anope
PORTVERSION=	1.8.2
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A set of IRC services for IRC networks

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" \
		--includedir="${LOCALBASE}/include" \
		--with-bindir=${PREFIX}/libexec/anope \
		--with-datadir=${DATADIR} \
		--with-rungroup=ircdru
USE_PERL5_BUILD=	yes

PORTDOCS=	BUGS COPYING DEFCON EVENTS \
		FAQ INSTALL IRCD MODULES MYSQL \
		NEWS PROXY README

USE_RC_SUBR=	anope

OPTIONS=	MYSQL "Use mysql" ON

.include <bsd.port.pre.mk>

# XXX Add here other arch which needs -fPIC :-)
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

pre-install:
	@${MKDIR} ${PREFIX}/libexec/anope
	@${MKDIR} ${DATADIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
