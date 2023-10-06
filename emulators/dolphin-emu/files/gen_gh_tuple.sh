#!/bin/sh

echo "GH_TUPLE= \\"
for _sm_root in $(find . -type f -name .gitmodules | sed 's/\.gitmodules$//' | sort)
do
  (
    cd "${_sm_root}"

    # Crawl name|path|url list of submodules within _sm_root
    grep -e '^\[submodule "' -e 'path = ' -e 'url = ' .gitmodules | \
      sed -E -e 's|.*"([^"]+)".*|\1|' -e 's|.*= ||' | \
      paste - - - | \
      sed -E 's/[[:space:]]+/|/g' | \
    while read _sm
    do
      _sm_name=$(echo "${_sm}" | cut -d '|' -f 1)
      _sm_path=$(echo "${_sm}" | cut -d '|' -f 2)
      _sm_url=$(echo "${_sm}" | cut -d '|' -f 3)

      _sm_prefix=$(echo "${_sm_root}" | sed 's|^\./||')

      _account_project=$(echo "${_sm_url}" | sed -e 's|^https://github.com/||' -e 's|/|:|g' -e 's|\.git$||')
      _group=$(echo "${_account_project}" | cut -d ':' -f 2 | tr -cd 'a-zA-Z0-9_')
      _tagname_group_subdir=$(git submodule status "${_sm_path}" | sed -E -e 's|^.||' -e "s|[[:space:]]+|:${_group}/${_sm_prefix}|" -e 's|[[:space:]]+.*$||')
      echo -e "\t${_account_project}:${_tagname_group_subdir} \\"
    done
  )
done
echo ""
