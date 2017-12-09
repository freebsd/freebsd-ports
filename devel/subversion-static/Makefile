# $FreeBSD$

PKGNAMESUFFIX=	-static

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}
OPTIONS_SLAVE=		FREEBSD_TEMPLATE P4_STYLE_MARKERS SERF STATIC

BROKEN_armv6 =		fails to link: (.text+0x1124e8): undefined reference to 'log' 20171201
BROKEN_armv7 =		fails to link: (.text+0x118018): undefined reference to 'log' 20171126

MASTERDIR=	${.CURDIR}/../subversion
PKGMESSAGE=	${.CURDIR}/pkg-message

# Set these by hands, as options are undefined
PLIST_SUB+=	TOOLS="@comment " \
		SVNSERVE_WRAPPER="@comment " \
		BDB="@comment " \
		NLS="@comment "

.include "${MASTERDIR}/Makefile"
