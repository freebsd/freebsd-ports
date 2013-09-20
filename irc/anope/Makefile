# Created by: mat
# $FreeBSD$

PORTNAME=	anope
PORTVERSION=	1.8.7
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/Anope%20${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A set of IRC services for IRC networks

USES=		gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" \
		--includedir="${LOCALBASE}/include" \
		--with-bindir=${PREFIX}/libexec/anope \
		--with-datadir=${DATADIR} \
		--with-rungroup=ircdru

PORTDOCS=	BUGS COPYING DEFCON EVENTS \
		FAQ INSTALL IRCD MODULES MYSQL \
		NEWS PROXY README

USE_RC_SUBR=	anope

OPTIONS_DEFINE=	MYSQL
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# XXX Add here other arch which needs -fPIC :-)
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

pre-install:
	@${MKDIR} ${PREFIX}/libexec/anope
	@${MKDIR} ${DATADIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
