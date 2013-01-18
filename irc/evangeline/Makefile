# Created by: Edini <ports@edini.net>
# $FreeBSD$

PORTNAME=	evangeline
PORTVERSION=	1.1.4
CATEGORIES=	irc tcl
MASTER_SITES=	http://www.averse.piasta.pl/_data/evangeline/${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}-b1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC Bot based on Eggdrop

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_TCL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/evangeline

OPTIONS_DEFINE=	IPV6 CRYPT
OPTIONS_DEFAULT=	CRYPT
CRYPT_DESC=	Enable Encryption

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MCRYPT}
CONFIGURE_ARGS+=	--enable-crypt
.else
CONFIGURE_ARGS+=	--disable-crypt
.endif

pre-everything::
	@${ECHO_MSG} 'To redefine the "admin" user name, set ADMIN_NAME'
	@${ECHO_MSG} 'To redefine the "Permanent owner" name, set OWNER_NAME'

post-patch:
	@${REINPLACE_CMD} 's,^read usersq,usersq=n,' ${WRKDIR}/evangeline/configure

# Turns out that putting ADMIN_NAME more than 9 chars creates an overflow...
# Fix that here while replacing the name.
post-configure:
.if !empty(ADMIN_NAME)
	@${REINPLACE_CMD} \
	    's,^char admin[^ ]* = [^;]*,const char* admin = "${ADMIN_NAME}",' \
	    ${WRKDIR}/evangeline/src/main.c
.endif
.if !empty(OWNER_NAME)
	@${REINPLACE_CMD} \
	    's,^char owner[^ ]* = [^;]*,const char* owner = "${OWNER_NAME}",' \
	    ${WRKDIR}/evangeline/src/main.c
.endif

.include <bsd.port.mk>
