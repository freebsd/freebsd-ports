# $FreeBSD$

PKGNAMESUFFIX=	-static

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*
LATEST_LINK=		${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}
OPTIONS_SLAVE=		FREEBSD_TEMPLATE P4_STYLE_MARKERS SERF STATIC

MASTERDIR=	${.CURDIR}/../subversion
PKGMESSAGE=	${.CURDIR}/pkg-message

# Set these by hands, as options are undefined
PLIST_SUB+=	TOOLS="@comment " \
		SVNSERVE_WRAPPER="@comment " \
		GNOME_KEYRING="@comment " \
		KDE_KWALLET="@comment " \
		BDB="@comment " \
		MOD_DAV_SVN="@comment " \
		NLS="@comment "

.include "${MASTERDIR}/Makefile"
