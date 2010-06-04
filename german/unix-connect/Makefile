# New ports collection makefile for:    unix-connect
# Date created:         01.May 1999
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	unix-connect
PORTVERSION=	0.95
CATEGORIES=	german comms news mail
MASTER_SITES=	ftp://ftp.dinoex.org/pub/unix-connect/ \
		SF		


MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Unix-Connect - mail+news-gateway for Zconnect (tm)

BUILD_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}
#USE_GMAKE=     yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-user=news
CONFIGURE_ARGS+=--with-group=dialer
CONFIGURE_ARGS+=--with-execdir=${PREFIX}/libexec/uconnect
CONFIGURE_ARGS+=--with-confdir=${PREFIX}/etc/uconnect
CONFIGURE_ARGS+=--with-spooldir=/var/spool/uconnect
CONFIGURE_ARGS+=--with-mail=sendmail
CONFIGURE_ARGS+=--with-news=cnews
CONFIGURE_ARGS+=--enable-testing
CFLAGS+=	-g
CFLAGS:=	${CFLAGS:S/-O[0-9]*//g}	# gcc generates broken code in uwsmtp

MANUAL_PACKAGE_BUILD=	needs hostname

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README INSTALL TODO ChangeLog ChangeLog.configure
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
	@${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
