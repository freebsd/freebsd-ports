# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.3.3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.gnokii.org/pub/gnokii/pre/ \
		http://linuxcare.com.au/download/gnokii/pre/ \
		ftp://multivac.fatburen.org/pub/gnokii/pre/ \
		ftp://urtica.linuxnews.pl/pub/people/pkot/gnokii/
DISTNAME=	${PORTNAME}-${PORTVERSION}_pre22

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_AUTOCONF=	yes
.if !defined(WITHOUT_X11)
USE_XPM=	yes
USE_GTK=	yes
.endif

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libintl=${PREFIX} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
.endif
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"

NO_PACKAGE=	"Group needs to be created"
MAN1=	gnokii.1
MAN8=	todologo.8

DOCDIR=${WRKSRC}/Docs
DOCDEST=${PREFIX}/share/doc/gnokii
FIXPREFIX=	Docs/DataCalls-QuickStart Docs/README common/cfgreader.c

post-patch:
.for f in ${FIXPREFIX}
	${PERL} -pi -e "s@/etc/gnokiirc@${PREFIX}/etc/gnokiirc@g" \
	${WRKSRC}/${f}
.endfor

pre-install:
	@${SH} ${SCRIPTDIR}/creategroup

post-install:
	@${INSTALL_DATA} ${DOCDIR}/sample/gnokiirc ${PREFIX}/etc/
	${INSTALL_MAN} ${DOCDIR}/man/todologo.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${GMAKE} install-docs)
	@${INSTALL} -d -o root -g wheel -m 0755 ${DOCDEST}
	@${INSTALL_DATA} ${DOCDIR}/ChangeLog ${PREFIX}/share/doc/gnokii/
	@${INSTALL_DATA} ${DOCDIR}/Bugs ${DOCDEST}/
	@${INSTALL_DATA} ${DOCDIR}/FAQ ${DOCDEST}/
	@${INSTALL_DATA} ${DOCDIR}/ChangeLog ${DOCDEST}/
	@${INSTALL_DATA} ${DOCDIR}/CodingStyle ${DOCDEST}/
	@${INSTALL_DATA} ${DOCDIR}/README-2110 ${DOCDEST}/
	@${INSTALL_DATA} ${DOCDIR}/test.vcs ${PREFIX}/share/doc/gnokii/
	@${INSTALL} -d -o root -g wheel -m 0755 ${DOCDEST}/protocol
	@${INSTALL_DATA} ${DOCDIR}/protocol/6110.txt ${DOCDEST}/protocol/
	@${INSTALL_DATA} ${DOCDIR}/protocol/7110.txt ${DOCDEST}/protocol/
	@${INSTALL} -d -o root -g wheel -m 0755 ${DOCDEST}/sample
	@${INSTALL_DATA} ${DOCDIR}/sample/options ${DOCDEST}/sample/
	@${INSTALL_DATA} ${DOCDIR}/sample/pap-secrets ${DOCDEST}/sample/
	@${INSTALL_DATA} ${DOCDIR}/sample/ppp-gnokii ${DOCDEST}/sample/
	@${INSTALL_DATA} ${DOCDIR}/sample/ppp-on ${DOCDEST}/sample/
.else
	${INSTALL_MAN} ${DOCDIR}/man/gnokii.1 ${PREFIX}/man/man1/
.endif
	@${ECHO} "================================================================================"
	@${ECHO} "The default config is installed in ${PREFIX}/etc/gnokiirc, and is configured"
	@${ECHO} "for Nokia 6110 phones connected on COM1. Have a look at the"
	@${ECHO} "documentation/manpages for more information."
	@${ECHO} "================================================================================"

.include <bsd.port.mk>
