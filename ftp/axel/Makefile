# ex:ts=8
# New ports collection makefile for:	axel
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axel
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	https://alioth.debian.org/frs/download.php/3015/ \
		ftp://ftp.linuxforum.hu/mirrors/frugalware/pub/frugalware/frugalware-testing/source/apps-extra/axel/ \
		http://cvs.fedoraproject.org/repo/pkgs/axel/axel-2.4.tar.gz/a2a762fce0c96781965c8f9786a3d09d/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	A download accelerator

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

OPTIONS=	NLS	"I18N support"		on	\
		DEBUG	"Debugging support"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
USE_ICONV=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=--i18n=1
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--i18n=0
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--debug=1 --strip=0
.endif

MAN1=		axel.1
MANLANG=	"" zh_CN

post-configure:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; \
		s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.settings

.include <bsd.port.post.mk>
