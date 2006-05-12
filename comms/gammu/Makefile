# New ports collection makefile for:   gammu
# Date created:        12 december 2003
# Whom:                Kirill Bezzubets <kirill@solaris.ru>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.06.00
CATEGORIES=	comms
MASTER_SITES=	http://www.mwiacek.com/zips/gsm/gammu/stable/1_0x/ \
		http://cihar.com/gammu/zips/gammu/stable/1_0x/

MAINTAINER=	bsam@ipt.ru
COMMENT=	GNU All Mobile Management Utilities

MAN1=		gammu.1
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259:env
INSTALLS_SHLIB=	yes

PORTDOCS=	*

CONFIGURE_ARGS=	--disable-bluerfsearch
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fPIC"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|%zd|%d|g' -e 's|%zi|%i|g' \
		${WRKSRC}/common/phone/at/atgen.c \
		${WRKSRC}/common/phone/obex/obexgen.c \
		${WRKSRC}/gammu/depend/nokia/dct3trac/wmx-gsm.c
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's@ installdocs@@g' \
		${WRKSRC}/cfg/Makefile.glo
.endif

.include <bsd.port.post.mk>
