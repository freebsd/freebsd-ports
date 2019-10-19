# $FreeBSD$

PORTNAME=	unix-connect
PORTVERSION=	0.95
PORTREVISION=	3
CATEGORIES=	german comms news mail
MASTER_SITES=	ftp://ftp.dinoex.org/pub/unix-connect/ \
		SF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Unix-Connect - mail+news-gateway for Zconnect (tm)

BUILD_DEPENDS=	lrz:comms/lrzsz

LICENSE_COMB=	multi
LICENSE=	GPLv2 BSD3CLAUSE

MANUAL_PACKAGE_BUILD=	needs hostname

USES=		fakeroot gperf

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
.if !defined(INSTALL_AS_USER)
CONFIGURE_ARGS+=--with-user=news
CONFIGURE_ARGS+=--with-group=dialer
.else
CONFIGURE_ARGS+=--with-user=`id -u -n`
CONFIGURE_ARGS+=--with-group=`id -g -n`
.endif
CONFIGURE_ARGS+=--with-execdir=${PREFIX}/libexec/uconnect
CONFIGURE_ARGS+=--with-confdir=${PREFIX}/etc/uconnect
CONFIGURE_ARGS+=--with-spooldir=/var/spool/uconnect
CONFIGURE_ARGS+=--enable-testing
CFLAGS+=	-g
CFLAGS:=	${CFLAGS:S/-O[0-9]*//g}	# gcc generates broken code in uwsmtp

DOC1=	README INSTALL TODO ChangeLog ChangeLog.configure

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	MAIL NEWS
OPTIONS_SINGLE_MAIL=	SENDMAIL POSTFIX QMAIL SMAIL NO_MAIL
OPTIONS_SINGLE_NEWS=	CNEWS INN NO_NEWS
OPTIONS_DEFAULT=SENDMAIL CNEWS
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
SENDMAIL_DESC=	build mail scripts for sendmail
POSTFIX_DESC=	build mail scripts for postfix
QMAIL_DESC=	build mail scripts for qmail
SMAIL_DESC=	build mail scripts for smail
NO_MAIL_DESC=	no mail scripts
CNEWS_DESC=	build news scripts for cnews
INN_DESC=	build news scripts for inn
NO_NEWS_DESC=	no news scripts
SENDMAIL_CONFIGURE_ON=	--with-mail=sendmail
POSTFIX_CONFIGURE_ON=	--with-mail=postfix
QMAIL_CONFIGURE_ON=	--with-mail=qmail
SMAIL_CONFIGURE_ON=	--with-mail=smail
NO_MAIL_CONFIGURE_ON=	--with-mail=no
CNEWS_CONFIGURE_ON=	--with-news=cnews
INN_CONFIGURE_ON=	--with-news=inn
NO_NEWS_CONFIGURE_ON=	--with-news=no

.include <bsd.port.options.mk>

pre-install:
	${MKDIR} ${STAGEDIR}/var/spool

post-install:
.if ${PORT_OPTIONS:MCNEWS}
	${INSTALL_SCRIPT} ${WRKSRC}/mail-and-news/cnews/viazconnect \
		${STAGEDIR}${PREFIX}/libexec/uconnect/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC1:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
