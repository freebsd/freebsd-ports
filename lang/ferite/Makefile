# New ports collection Makefile for:	ferite
# Date created:				21 August 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ferite
PORTVERSION=	0.99.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTRHEAD_CFLAGS%%|${PTHREAD_CFLAGS}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:S/"//g}|g' \
		${WRKSRC}/configure ${WRKSRC}/ferite-config.in

.include <bsd.port.mk>
