# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	distcc
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://ftp.samba.org/ftp/distcc/

MAINTAINER=	frerich.raabe@gmx.de

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	ps2pdf:${PORTSDIR}/print/ghostscript-gnu

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${CPPFLAGS}" \
	LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}"

MAN1=	distcc.1 distccd.1

DOC_FILES=	distcc.pdf distcc.ps distcc.html \
	distccd.pdf distccd.ps distccd.html

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/distccd ${PREFIX}/sbin

post-install: install-doc install-man
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${DOCSDIR}
.endfor
.endif

install-man:
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
