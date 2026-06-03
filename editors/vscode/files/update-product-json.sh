#! /bin/sh

PATH=/bin:/usr/bin:/usr/local/bin

WRKSRC=$1
PRODUCT_JSON=product.json

setpath() {
    json=$(jq --tab --arg value "${2}" "setpath(path(.${1}); \$value)" ${PRODUCT_JSON})
    echo "${json}" > ${PRODUCT_JSON}
}

setpath_json() {
    json=$(jq --tab --argjson value "${2}" "setpath(path(.${1}); \$value)" ${PRODUCT_JSON})
    echo "${json}" > ${PRODUCT_JSON}
}

cd ${WRKSRC}

mv -f ${PRODUCT_JSON} ${PRODUCT_JSON}.bak
echo '{}' > ${PRODUCT_JSON}

setpath "checksumFailMoreInfoUrl"	"https://go.microsoft.com/fwlink/?LinkId=828886"
setpath "documentationUrl"		"https://go.microsoft.com/fwlink/?LinkID=533484"
setpath_json "extensionsGallery"	'{"serviceUrl": "https://open-vsx.org/vscode/gallery", "itemUrl": "https://open-vsx.org/vscode/item", "latestUrlTemplate": "https://open-vsx.org/vscode/gallery/{publisher}/{name}/latest", "controlUrl": "https://raw.githubusercontent.com/EclipseFdn/publish-extensions/refs/heads/master/extension-control/extensions.json"}'
setpath "introductoryVideosUrl"	"https://go.microsoft.com/fwlink/?linkid=832146"
setpath "keyboardShortcutsUrlLinux"	"https://go.microsoft.com/fwlink/?linkid=832144"
setpath_json "linkProtectionTrustedDomains"	'["https://open-vsx.org"]'
setpath "quality"			"stable"
setpath "releaseNotesUrl"		"https://go.microsoft.com/fwlink/?LinkID=533483"
setpath "requestFeatureUrl"		"https://go.microsoft.com/fwlink/?LinkID=533482"
setpath "tipsAndTricksUrl"		"https://go.microsoft.com/fwlink/?linkid=852118"
setpath "twitterUrl"			"https://go.microsoft.com/fwlink/?LinkID=533687"
setpath_json "tunnelApplicationConfig"	'{}'

json=$(jq --tab --slurp '.[0] * .[1] * .[2]' ${PRODUCT_JSON}.bak ${PRODUCT_JSON} ${FILESDIR}/product.json.extensions)
echo "${json}" > ${PRODUCT_JSON}
