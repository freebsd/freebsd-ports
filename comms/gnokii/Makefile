# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.4.3
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://freesoftware.fsf.org/download/gnokii/
#		ftp://ftp.gnokii.org/pub/gnokii/

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
.if !defined(WITHOUT_X11)
USE_XPM=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
.endif
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libintl=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
.endif
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext"

NO_PACKAGE=	"Group needs to be created"
MAN1=	gnokii.1 todologo.1
.if !defined(WITHOUT_X11)
MAN1+=	xgnokii.1
.endif
MAN8=	gnokiid.8 mgnokiidev.8

INSTALL_TARGET=	install-suid

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c po/et.po po/sl.po

post-patch:
.for f in ${FIXPREFIX}
	@${SED} -e "s:/etc/gnokiirc:${PREFIX}/etc/gnokiirc:g" \
	< ${WRKSRC}/${f} > ${WRKSRC}/${f}.post_sed
	@${CP} ${WRKSRC}/${f}.post_sed ${WRKSRC}/${f}
.endfor
	@${SED} -e "s:%%PTHREAD_LIBS%%:${PTHREAD_LIBS}:" \
		-e "s:%%PTHREAD_CFLAGS%%:${PTHREAD_CFLAGS}:" \
	< ${WRKSRC}/configure > ${WRKSRC}/configure.post_sed
	@${CP} ${WRKSRC}/configure.post_sed ${WRKSRC}/configure

pre-install:
	@${SH} ${SCRIPTDIR}/creategroup

post-install:
	@(cd ${WRKSRC} && ${GMAKE} install-docs)
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${PREFIX}/etc/gnokiirc.sample
	${INSTALL_DATA} ${WRKSRC}/common/libgnokii.so ${PREFIX}/lib/
	@(cd ${PREFIX}/lib && ${LN} -s libgnokii.so libgnokii.so.0)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
