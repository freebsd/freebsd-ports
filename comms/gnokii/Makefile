# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.3.3
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.gnokii.org/pub/gnokii/ \
		ftp://urtica.linuxnews.pl/pub/people/pkot/gnokii/

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_AUTOCONF=	yes
.if !defined(WITHOUT_X11)
USE_XPM=	yes
USE_GTK=	yes
.endif

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libintl=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
.endif

NO_PACKAGE=	"Group needs to be created"
MAN1=	gnokii.1 todologo.1
.if !defined(WITHOUT_X11)
MAN1+=	xgnokii.1
.endif
MAN8=	gnokiid.8 mgnokiidev.8

INSTALL_TARGET=	install-suid

pre-install:
	@${SH} ${SCRIPTDIR}/creategroup

post-install:
	@(cd ${WRKSRC} && ${GMAKE} install-docs)
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
	    ${PREFIX}/etc/gnokiirc.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
