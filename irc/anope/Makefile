# Created by: mat
# $FreeBSD$

PORTNAME=	anope
PORTVERSION=	1.8.9
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-legacy/Anope%20${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Set of IRC services for IRC networks

USES=		perl5 gmake desthack
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" \
		--includedir="${LOCALBASE}/include" \
		--with-bindir=\$${${DESTDIRNAME}}${PREFIX}/libexec/anope \
		--with-datadir=\$${${DESTDIRNAME}}${DATADIR}

PORTDOCS=	BUGS COPYING DEFCON EVENTS \
		FAQ INSTALL IRCD MODULES MYSQL \
		NEWS PROXY README

USE_RC_SUBR=	anope

OPTIONS_DEFINE=	MYSQL
OPTIONS_DEFAULT=	MYSQL

MYSQL_USE= mysql=yes
MYSQL_CONFIGURE_WITH=	mysql

.include <bsd.port.pre.mk>

# XXX Add here other arch which needs -fPIC :-)
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ja_utf8|ja|g' ${WRKSRC}/lang/Makefile
	${MV} ${WRKSRC}/lang/ja_utf8.l ${WRKSRC}/lang/ja.l

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/anope
	@${MKDIR} ${STAGEDIR}${DATADIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
