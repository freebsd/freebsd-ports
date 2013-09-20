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
COMMENT=	A download accelerator

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

OPTIONS_DEFINE=	NLS DEBUG

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=--i18n=1
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--i18n=0
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--debug=1 --strip=0
.endif

MAN1=		axel.1
MANLANG=	"" zh_CN

post-configure:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; \
		s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.settings

.include <bsd.port.mk>
