# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wget
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	ftp www
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	sf@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=	--with-ssl=no
.else
USE_OPENSSL=	yes
.endif
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

MAN1=		wget.1

post-patch:
	${RM} -f ${WRKSRC}/doc/wget.info*
# we don't need to run autoconf.
	${TOUCH} ${WRKSRC}/configure

post-install:
	install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
