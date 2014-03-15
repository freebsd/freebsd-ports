# Created by: mat
# $FreeBSD$

PORTNAME=	anope
PORTVERSION=	1.8.8
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/Anope%20${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A set of IRC services for IRC networks

USES=		perl5 gmake
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

post-patch:
	@${REINPLACE_CMD} -e 's|ja_utf8|ja|g' ${WRKSRC}/lang/Makefile
	${MV} ${WRKSRC}/lang/ja_utf8.l ${WRKSRC}/lang/ja.l

pre-install:
	@${MKDIR} ${PREFIX}/libexec/anope
	@${MKDIR} ${DATADIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
