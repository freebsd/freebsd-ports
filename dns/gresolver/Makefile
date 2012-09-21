# New ports collection makefile for:	gresolver
# Date created:			23 Oct 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gresolver
PORTVERSION=	0.0.5
PORTREVISION=	6
CATEGORIES=	dns
MASTER_SITES=	http://jodrell.net/files/unsupported/gresolver/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical DNS query tool using GTK+

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

RUN_DEPENDS=	p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Glade2>=0:${PORTSDIR}/x11-toolkits/p5-Glade2 \
		p5-Net-IPv6Addr>=0:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr

USE_PERL5=	yes

.include <bsd.port.pre.mk>

# The Perl script uses GtkFileChooser widgets, which need libpthread
# through /usr/X11R6/lib/gtk-2.0/2.4.0/filesystems/libgnome-vfs.so.
# Unfortunately, on FreeBSD, if an application uses a library which
# uses libpthread, the application itself must link against
# libpthread. This is why a threaded Perl is required.

HAVE_THREADS!=	${PERL} -mthreads -e '' >/dev/null 2>&1 && ${ECHO_CMD} 'yes' || true

.if empty(HAVE_THREADS)
IGNORE=		needs a threaded Perl, install lang/perl5.8 with threads support and try again
.endif

do-build:
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/gresolver.pl > ${WRKSRC}/gresolver

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gresolver ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gresolver.desktop ${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gresolver.png ${PREFIX}/share/pixmaps
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gresolver.glade ${DATADIR}

.include <bsd.port.post.mk>
