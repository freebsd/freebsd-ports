# New ports collection Makefile for:	ferite
# Date created:				21 August 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ferite
PORTVERSION=	0.99.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ishmael27@home.com

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake

LIB_DEPENDS=	ltdl.1:${PORTSDIR}/devel/libtool \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql" \
		sql_CFLAGS="-I${LOCALBASE}/include/mysql" \
		sql_LIBS="-L${LOCALBASE}/lib/mysql -lmysqlclient -lz \
			-lcrypt -lm"

EXTRA_DOCS=	AUTHORS COPYING ChangeLog README ROADMAP TODO

.if defined(NOPORTDOCS)
MAKE_ENV=	DOCS=""
.else
MAKE_ENV=	DOCS=docs
post-install:
.for i in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/ferite
.endfor
.endif

post-patch:
	@${PERL} -pi -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:S/"//g}|g' \
		${WRKSRC}/ferite-config.in

post-configure:
	@${PERL} -pi -e 's|^s%\@LIBS.*|s%\@LIBS\@%-L${LOCALBASE}/lib%g|' \
		${WRKSRC}/config.status

.include <bsd.port.mk>
