# Created by: ijliao
# $FreeBSD$

PORTNAME=	axel
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	https://alioth.debian.org/frs/download.php/3015/ \
		ftp://ftp.linuxforum.hu/mirrors/frugalware/pub/frugalware/frugalware-testing/source/apps-extra/axel/ \
		http://cvs.fedoraproject.org/repo/pkgs/axel/axel-2.4.tar.gz/a2a762fce0c96781965c8f9786a3d09d/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	Download accelerator

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

OPTIONS_DEFINE=	NLS DEBUG
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ON=	--i18n=1
NLS_CONFIGURE_OFF=	--i18n=0
DEBUG_CONFIGURE_ON=--debug=1 --strip=0

post-configure:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; \
		s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.settings

.include <bsd.port.mk>
