# New ports collection makefile for:   dvdrip
# Date created:	18 April 2002
# Whom:		Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	dvdrip
PORTVERSION=	0.44
CATEGORIES=	graphics
MASTER_SITES=	http://www.exit1.org/dvdrip/dist/
DISTNAME=	Video-DVDRip-${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net

.if !defined(WITHOUT_CLUSTER)
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event \
		${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping \
		pstree:${PORTSDIR}/sysutils/pstree
.endif
.if defined(WITH_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/graphics/xine \
		${X11BASE}/lib/xine/plugins/xineplug_inp_d4d.so:${PORTSDIR}/graphics/xine_d4d_plugin
.endif
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick \
		transcode:${PORTSDIR}/graphics/transcode
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk/Gdk/Pixbuf.pm:${PORTSDIR}/x11-toolkits/p5-GdkPixbuf

PERL_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		splitpipe.1

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Video::DVDRip.3

pre-everything::
.if !defined(WITHOUT_CLUSTER)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable the cluster daemon and it's"
	@${ECHO_MSG} "dependencies by defining WITHOUT_CLUSTER."
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: dvdrip does not like this and will"
	@${ECHO_MSG} "throw cryptic error-messages. Use with caution."
.endif
.if !defined(WITH_XINE)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_XINE to pull in XINE as a dependency"
	@${ECHO_MSG} "(used for previewing DVDs prior to ripping)"
	@${ECHO_MSG}
.endif

post-patch:
	@${PERL} -pi -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#' \
		${WRKSRC}/lib/Video/DVDRip/Cluster/Master.pm
	@${PERL} -pi -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/dvdrip
	@${PERL} -pi -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/dvdrip-master
	@${PERL} -pi -e 's#cc#${CC}#' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
