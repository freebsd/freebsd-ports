# ex:ts=8
# New ports collection makefile for:	muddleftpd
# Date created:			Apr 22, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	muddleftpd
PORTVERSION=	1.3.9
CATEGORIES=	ftp
MASTER_SITES=	http://www.arach.net.au/~wildfire/muddleftpd/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

GNU_CONFIGURE=	yes

USE_GMAKE=	yes
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_DATA="${INSTALL_DATA}"

MAN1=	muddleftpd.1 ftpwho.1 mudpasswd.1
EXAMPLES=	anon-only.conf anon-reigon.conf ratios.conf standard.conf \
		vserver-host.conf vserver.conf vserverbig.conf
DOCS=	cookie.txt ftpcmds.txt muddleftpd.txt mudpasswd.txt reference.txt

post-install:
	install-info ${PREFIX}/info/muddleftpd.info ${PREFIX}/info/dir
	@${MKDIR} ${PREFIX}/share/examples/muddleftpd
	${CP} ${WRKSRC}/examples/README ${PREFIX}/share/examples/muddleftpd
.for file in ${EXAMPLES}
	${CP} ${WRKSRC}/examples/${file} ${PREFIX}/share/examples/muddleftpd
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/muddleftpd
.for file in ${DOCS}
	${CP} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/muddleftpd
.endfor
.endif

.include <bsd.port.mk>
