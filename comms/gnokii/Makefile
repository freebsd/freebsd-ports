# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.5.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://freesoftware.fsf.org/download/gnokii/ \
		ftp://ftp.gnokii.org/pub/gnokii/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to talk to Nokia cellular phones

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_GMAKE=	yes
.if !defined(WITHOUT_X11)
USE_XPM=	yes
USE_GNOME=	gtk12
.endif
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
.endif
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	gnokii.1 todologo.1
.if !defined(WITHOUT_X11)
MAN1+=	xgnokii.1
.endif
MAN8=	gnokiid.8 mgnokiidev.8

INSTALL_TARGET=	install-suid
PKGDEINSTALL=	${PKGINSTALL}

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c po/et.po po/sl.po

post-patch:
.for f in ${FIXPREFIX}
	@${REINPLACE_CMD} -e "s:/etc/gnokiirc:${PREFIX}/etc/gnokiirc:g" \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "s:%%PTHREAD_LIBS%%:${PTHREAD_LIBS}:; \
		s:%%PTHREAD_CFLAGS%%:${PTHREAD_CFLAGS}:" ${WRKSRC}/configure
.for f in common/data/virtmodem.c utils/mgnokiidev.c
	@${REINPLACE_CMD} -E -e "s:^(#ifdef.*)__OpenBSD__:\1__FreeBSD__:" \
		${WRKSRC}/${f}
.endfor

pre-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@(cd ${WRKSRC} && ${GMAKE} install-docs)
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${PREFIX}/etc/gnokiirc.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
